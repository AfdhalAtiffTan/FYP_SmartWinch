# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\Users\AfdhalAtiffTan\Documents\PSoC Creator\smart_winch_prototype\Workspace01\Prototype.cydsn\Prototype.cyprj
# Date: Mon, 29 Jan 2018 22:37:48 GMT
#set_units -time ns
create_clock -name {Clock_1(FFB)} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/ff_div_11}] [get_pins {ClockBlock/ff_div_12}] [get_pins {ClockBlock/ff_div_14}]]
create_clock -name {Clock_3(FFB)} -period 10000 -waveform {0 5000} [list [get_pins {ClockBlock/ff_div_13}]]
create_clock -name {SPI_SCBCLK(FFB)} -period 125 -waveform {0 62.5} [list [get_pins {ClockBlock/ff_div_2}]]
create_clock -name {ADC_intClock(FFB)} -period 125 -waveform {0 62.5} [list [get_pins {ClockBlock/ff_div_10}]]
create_clock -name {USB_UART_SCBCLK(FFB)} -period 541.66666666666663 -waveform {0 270.833333333333} [list [get_pins {ClockBlock/ff_div_5}]]
create_clock -name {CyRouted1} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/dsi_in_0}]]
create_clock -name {CyILO} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/ilo}]]
create_clock -name {CyLFClk} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/lfclk}]]
create_clock -name {CyIMO} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyHFClk} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/hfclk}]]
create_clock -name {CySysClk} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/sysclk}]]
create_generated_clock -name {Clock_1} -source [get_pins {ClockBlock/hfclk}] -edges {1 2 3} [list]
create_generated_clock -name {Clock_3} -source [get_pins {ClockBlock/hfclk}] -edges {1 481 961} [list]
create_generated_clock -name {SPI_SCBCLK} -source [get_pins {ClockBlock/hfclk}] -edges {1 7 13} [list]
create_generated_clock -name {ADC_intClock} -source [get_pins {ClockBlock/hfclk}] -edges {1 7 13} [list]
create_generated_clock -name {USB_UART_SCBCLK} -source [get_pins {ClockBlock/hfclk}] -edges {1 27 53} -nominal_period 541.66666666666663 [list]


# Component constraints for C:\Users\AfdhalAtiffTan\Documents\PSoC Creator\smart_winch_prototype\Workspace01\Prototype.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\AfdhalAtiffTan\Documents\PSoC Creator\smart_winch_prototype\Workspace01\Prototype.cydsn\Prototype.cyprj
# Date: Mon, 29 Jan 2018 22:37:45 GMT
