# @Author: Petros Morfiris, Konstantinos L. Papageorgiou - Agrofelis 2023

server <- function(input, output, session) {

  update_dataset_choices <- function() updateSelectInput(session, "select_dataset", choices = get_dirnames())

  datasets <- observe({
    update_dataset_choices()
  })

  dataset <- reactive({
    req(input$select_dataset)
    path_to_data <- paste0("data/lidar/", input$select_dataset, "/deg_vs_dist.csv")
    deg_vs_dist <- fread(path_to_data)
    updateSliderInput(session, "select_chunk", min = 1, max = max(deg_vs_dist[, chunk]), value = 1)
    deg_vs_dist
  })

  dat <- reactive({
    x <- dataset()[chunk == input$select_chunk]
    if(input$filter_80_quantile)
      x <- x[distance < quantile(distance, 0.80)[[1]]] # Keep obs with distance less than 80th quantile
    x
  })

  observeEvent(input$upload_file, {

    file_dir <- paste0("data/lidar/", trim_filename(input$upload_file$name))
    if(dir.exists(file_dir)) {
      showNotification("File already exists. Remove before re-uploading.", type = "warning")
    } else {
      # Move file and creare necessary folders
      file_meta <- move_file(input$upload_file$name, input$upload_file$datapath)

      # Bring file into format
      shape_dataset(file_meta$log_path, file_meta$data_path)

      # Update the select input in the first tab
      update_dataset_choices()

      showNotification("File uploaded and transformed successfully.", type = "message")
    }

  })

  observeEvent(input$remove_file, {
    if(length(get_dirnames()) > 1) {
      showModal(modalDialog(
        title = "Are you sure?",
        glue("You are about to delete the \"{input$select_dataset}\" logs. Are you sure?"),
        footer = tagList(
          modalButton("Cancel", icon = icon("cancel")),
          actionButton("accept_delete", "OK")
        )
      ))
    } else {
      showNotification("At least one file must exist!", type = "warning")
    }
  })

  observeEvent(input$accept_delete, {
    req(input$select_dataset)
    unlink(paste0("data/lidar/", input$select_dataset), recursive = TRUE)
    update_dataset_choices()
    removeModal(session)
    showNotification("File removed successfully.", type = "message")
  })

  vis_plot <- reactive(plot_lidar(dat(), input$use_plot_line))

  output$linearPlot <- renderUI({
    svg_plot(vis_plot())
  })

  output$polarPlot <- renderUI({
    gg <- vis_plot() +
      coord_polar(direction = 1)

    svg_plot(gg)
  })
}
