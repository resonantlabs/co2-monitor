# CO2 Sensor using an STM32 Nucleo
This project uses a STM32G474 Nucleo board and a Senseair CO2 Module
![Project](/assets/assembly.jpg)

The STM32 captures CO2 PPM every 10 seconds and stores it in a global variable. I also blast it out of the VCP of STM32.

![Watch Window](/assets/watch.png)

## Parts list

1. STM32G474 Nucleo Board [ST LINK](https://www.st.com/en/evaluation-tools/nucleo-g474re.html)
2. CO2 Sensor 006-1-0100 [Digikey](https://www.digikey.ca/en/products/detail/senseair/006-1-0100/17125330?gclsrc=aw.ds&gad_source=1&gad_campaignid=17336435733&gbraid=0AAAAADrbLlhyW11R7GyOzdog9tzdGFKKd&gclid=CjwKCAjw-svEBhB6EiwAEzSdruNGYVJdDa42w4Qtv-iv5keLgySBxPVarkBEUQO4J2ghxmu8yhcj9hoCbWgQAvD_BwE)
3. PCB for easy mounting [Gerber Files](/PCB/CO2%20Daughter%20Board.zip)

*You can also space-wire (wire directly ) if needed*

The PCB also has provisions for a relay, which might be handy to turn on a fan.

![Schematic](/assets/schematic.png)

## Code Requirements

1. VSCODE
2. CMAKE / NINJA
3. GIT
4. STM32G4 Library [Link](https://github.com/STMicroelectronics/STM32CubeG4)
5. ARM GCC Toolchain
6. ThreadX [Link](https://github.com/eclipse-threadx/threadx)
7. STUTIL [Link](https://github.com/stlink-org/stlink)

### VSCODE plugins
1. CMAKE Tools
2. Marcus Cortex-Debug

*6 - you will need to compile the ThreadX separately as I link to it outside this project
*7 - STUTIL is the opensource version you can also STM32CUBE flavor

## Final Thoughts

I like this build environment using VSCODE/CMAKE. It feels like I have reached some sort of IDE Nirvana finally. 

Let me know if I can help with anything. I was awfully terse in this readme.

