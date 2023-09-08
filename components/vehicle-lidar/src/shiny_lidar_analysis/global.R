# @Author: Petros Morfiris, Konstantinos L. Papageorgiou - Agrofelis 2023

library(shiny)
library(data.table)
library(magrittr)
library(ggplot2)
library(svglite)
library(bslib)
library(glue)

register_devmode_option(
  "shiny.autoreload",
  "Turning on shiny autoreload. To disable, call `options(shiny.autoreload = FALSE)`",
  devmode_default = TRUE
)

source("helpers.R")
