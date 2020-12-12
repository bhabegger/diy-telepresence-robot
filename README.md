# DIY Telepresence Robot

This project is the codebase for a DIY telepresence robot based on the Robot 2WD Car kit using an Arduino UNO in combination with an ESP32-Cam
It provides a simple web interface to connect to the robot and control it.

## How it works

### Sketches

The code base is composed of two sketches:
* ESP32-HttpServer : An HttpServer sketch targeted for the ESP32-CAM
* RobotComplete: A Robot sketch targeted for the Arduino UNO 

### Http Server

The httpserver has the following endpoints
* `/`
  
    Serves a basic GUI to allow to receive the Robot Cam stream and send control requests
  
* `/stream`
  
  Provides the stream (to a single client) of the ESP32 camera

* `/forward` - called by the up arrow button in the GUI

  Tells the robot to go forward

* `/backward` - called by the down arrow button in the GUI

  Tells the robot to go backward

* `/left` - called by the left arrow button in the GUI

  Tells the robot to go turn left

* `/right` - called by the right arrow button in the GUI

  Tells the robot to go turn right


* `/stop` - called by the square button in the GUI

  Tells the robot to stop

### ESP32 and Arduino communication

The ESP32 and Arduino are connected together through an I2C channel (two wire communication protocol) with the ESP32 being the master.

The commands the Arduino Robot sketch understands are:

* `forward`
  
    making both wheels go forward at the same speed (full speed)
  
* `backward`
    
    making both wheels go backward at the same speed (half speed)
  
* `right`
  
    slowing down the right wheel, so the robot goes right (multiple calls will cumulate the decrease)

* `left`
  
    slowing down the left wheel, so the robot goes left (multiple call will cumulate the decrease)
  
* `stop`        

    stopping both wheels

## Making the robot

### Step. 0 Getting the material

Here is the basic material:

* A robot kit:
    * Search for "arduino 2wd robot car" on the web and you should easily find one
* An ESP32-CAM:
    * Search for "esp32-cam" and you should find one
* Some wood, plexiglass or whatever you'd like to work with to give the robot the shape you want and connect the pieces together
* Some screws and bolts of different sizes (standard M3, M4, M5 screws with different bolt lengths will likely be handy)
* Imagination :)

### Step 1. Build the robot

There are multiple tutorials out there to start with the kit. Just follow anyone of them found by searching for "2wd arduino robot car instructions".

IMPORTANT NOTE: The pin setup of the tutorials, and those in this codebase may differ. So either you adapt the pin numbers of the tutorials to be in phase with those using in this codebase, either you adapt your copy of this code to adjust to those of you robot. Just be careful that all Arduino pins provide the same functionality (e.g. PWM, Pulse Width Modulation). While it is always doable, once you have something working, you may not really feel like having to rewire everything :)

### Step 2. Getting the robot to run on its own

You likely want to get started by getting the robot working on its own independently of this code base. So get one of the tutorial sketches into the robot and get running like that and why not play around a bit with it :)

### Step 3. Setting up the ESP32

You can follow one of the tutorials to setup the Arduino IDE to recognize the ESP32 board by searching for "esp32 arduino ide". (For example: https://randomnerdtutorials.com/program-upload-code-esp32-cam/)

NOTE: The Makefile files in this project allow uploading code to the ESP32 and Arduino independantly of the Arduino IDE. However, they will still need the arduino command to recognize the board, so the setup process is still necessary

### Step 4. Connection setup

The code should make it quite explicit what the pin setup is (and it can be worth a check that this doc is not outdated, time or writing being 2020.12.12)

| Arduino PIN | Usage                 | Connected to                      | Notes           |
|-------------|-----------------------|-----------------------------------|-----------------| 
| 6           | Left wheel speed      | Motor Controller Board `ENA` Pin  | PWM required   |
| 10          | Left wheel forward    | Motor Controller Board `IN1` Pin  | |
| 11          | Left wheel backard    | Motor Controller Board `IN2` Pin  | |
| 5           | Right wheel speed     | Motor Controller Board `ENB` Pin  | PWM required   |
| 9           | Right wheel forward   | Motor Controller Board `IN3` Pin  | |
| 8           | Right wheel backard   | Motor Controller Board `IN4` Pin  | |
| A4          | I2C Data Wire (SDA)   | ESP32 Pin 15                      | |
| A5          | I2C Clock Wire (SCL)  | ESP32 Pin 13                      | |
| 12          | Sonar Trigger         | Sonar Trig Pin                    | |
| 13          | Sonar Echo            | Sonar Echo Pin                    | |
| 11          | Servo direction       | Servo                             | |

NOTE: The previous table doesn't show them but don't forget to connect the 5V VCC and GND to the appropriate places.




