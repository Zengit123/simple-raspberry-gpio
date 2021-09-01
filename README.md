## simple-raspberry-gpio is for those who want simple control of Raspberry Pi GPIO pins without spending time setting up dependencies.
This is a single file C++ program that does not need additional libraries, making it easy to install and use.
After a simple setup, you will be able to manually control GPIO pins through command-line interface (terminal) or include it in other programs/protocols such as Bash, Python, C++, Crontab, SSH, etc.

Do not use this program for high-speed control of GPIO pins, give it at least 0.1 seconds to execute.

## How to use
After installing, you will be able to control GPIO pins in command-line interface (terminal) following this fashion:
> simplegpio [COMMAND] [PIN_NUMBER] [OPTION]

#### Commands
* *export [PIN_NUMBER]* - a pin must be exported before use, otherwise it will not work.
* *unexport [PIN_NUMBER]* - sets output to *0* and pin mode to *in*, then unexports it. Although not obligatory, it is recommended to do this if a pin is no longer used.
* *getmode [PIN_NUMBER]* - prints pin mode to console as either *in* or *out*.
* *setmode [PIN_NUMBER] [ in | out ]* - sets pin mode.
* *read [PIN_NUMBER]* - prints pin value to console as either *0* or *1*.
* *write [PIN_NUMBER] [ low | high ]* - sets pin output value.

#### Examples
> simplegpio export 22<br>
> simplegpio getmode 22<br>
> in<br>
> simplegpio setmode 22 out<br>
> simplegpio write 22 high<br>
> simplegpio write 22 low<br>
> simplegpio setmode 22 in<br>
> simplegpio read 22<br>
> 0<br>
> simplegpio unexport<br>

## Installing
Download the *gpio_control.cpp* file to your Raspberry-Pi either directly from github repository or using command-line git, then enter it:
> cd ~ <br>
> git clone https://github.com/Zengit123/simple-raspberry-gpio.git <br>
> cd simple-raspberry-gpio <br>

Compile the program:
> sudo g++ gpio_control.cpp -o /bin/simplegpio <br>

Now you can safely remove the downloaded files to declutter home directory, program is already installed:
> cd .. <br>
> rm -rf ~/simple-raspberry-gpio <br>

#### Uninstalling
If you wish to remove this command-line utility, simply run:
> sudo rm /bin/simplegpio
