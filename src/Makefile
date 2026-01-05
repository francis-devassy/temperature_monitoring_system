#Compiler to use
CC = gcc
#Compiler flags
CFLAGS = -Wall
#Include directories
INCLUDES =
INCLUDES += -I./common
INCLUDES += -I./sensor
INCLUDES += -I./alarmManager
INCLUDES += -I./temperatureMonitoring
CFLAGS += $(INCLUDES)
#Source files
SRCS = 
SRCS += main.c
SRCS += alarmManager/alarmManager.c
SRCS += sensor/sensor.c
SRCS += temperatureMonitoring/temperatureMonitoring.c
#Build target temperatureMonitoringSystem
main: $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o temperatureMonitoringSystem
#Build debug target debugTemperatureMonitoringystem
debug: $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -g -o debugTemperatureMonitoringSystem
#Run gdb on the binary
gdb: debugTemperatureMonitoringSystem
	gdb ./debugTemperatureMonitoringSystem
#Clean target
clean:
	rm -f temperatureMonitoringSystem debugTemperatureMonitoringSystem
#Delete the data file
del:ls
	rm -f data.dat