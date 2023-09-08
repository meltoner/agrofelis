# @Author: Petros Morfiris, Konstantinos L. Papageorgiou - Agrofelis 2023

filter_component <- function() {
  div(
    class = "p-2",
    selectInput("select_dataset", "Select dataset:", choices = c()),
    sliderInput("select_chunk", "Select chunk:", min = 1, max = 100, value = 1, step = 1),
    fluidRow(
      column(
        6,
        checkboxInput("filter_80_quantile", "Filter outliers (80th quantile)", value = TRUE),
      ),
      column(
        3,
        checkboxInput("use_plot_line", "Plot line", value = FALSE)
      ),
      column(
        3,
        actionLink("remove_file", "Delete file", icon = icon("remove"), class = "text-decoration-none")
      )
    )
  )
}

upload_component <- function() {
  div(
    class = "p-2",
    fileInput("upload_file", "Upload a file")
  )
}

ui <- fluidPage(

  theme = bs_theme(version = 5, "cerulean"),

  titlePanel("Agrofelis Lidar visualisation"),

  sidebarLayout(
    sidebarPanel(
      tabsetPanel(
        id = "component_tabs",
        tabPanel("Filter logs", filter_component()),
        tabPanel("Upload logs", upload_component())
      )
    ),
    mainPanel(
      card(
        card_header("Visualisations"),
        fluidRow(
          column(6, htmlOutput("linearPlot", fill = TRUE)),
          column(6, htmlOutput("polarPlot", fill = TRUE))
        )
      )
    )
  )
)
