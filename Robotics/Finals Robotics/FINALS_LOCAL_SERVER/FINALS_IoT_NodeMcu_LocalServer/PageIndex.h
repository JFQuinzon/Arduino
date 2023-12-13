const char MAIN_page[] PROGMEM = R"=====(

<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <link rel="stylesheet" href="styles.css" />
    <style>
      body {
        font-family: Arial, sans-serif;
        display: flex;
        justify-content: center;
        align-items: center;
        height: 100vh;
        margin: 0;
        background-color: #f0f0f0;
        text-align: center;
        font-size: 22px;
        padding: 0;
      }
      .robot-controller {
        display: flex;
        flex-direction: column;
        gap: 20px;
        padding: 20px;
        background-color: #fff;
        border-radius: 10px;
        box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);
      }

      .button {
        padding: 10px 20px;
        font-size: 20px;
        font-weight: bold;
        border: none;
        border-radius: 50px;
        cursor: pointer;
        width: 180px;
        height: 60px;
        box-shadow: 0 0 10px rgba(0, 0, 0, 0.567);
        margin: 0 20px;
      }

      .button:hover {
        opacity: 0.8;
      }

      .red {
        background-color: #ff6347;
        color: #fff;
      }

      .green {
        background-color: #4caf50;
        color: #fff;
      }

      .blue {
        background-color: #2196f3;
        color: #fff;
      }

      .yellow {
        background-color: #c502c5;
        color: #fff;
      }

      .pink {
        background-color: #ff6eb4;
        color: #fff;
      }
      #joystick-container {
        display: flex;
        align-items: center;
        justify-content: center;
      }

      #stick2,
      #stick1 {
        margin-left: -102px;
        margin-top: -2px;
      }
      .joystick {
        display: flex;
        justify-items: center;
        justify-content: space-around;
        margin-left: -45px;
        margin-bottom: -30px;
      }
      .base {
        background-color: white;
        height: 140px;
        width: 140px;
        border-radius: 50%;
        border: 2px solid rgb(132, 132, 132);
      }
      .stick1,
      .stick2 {
        background-color: #4caf50;
        height: 60px;
        width: 60px;
        border-radius: 50%;
      }
    </style>

    <title>FINALS ROBOTICS</title>
  </head>
  <body>
    <div class="robot-controller">
      <div class="actuator">
        <h3>Actuator</h3>
        <input
          type="range"
          min="-100"
          max="100"
          value="0"
          id="baseRange"
          style="display: none"
        />
        <input
          type="range"
          min="-100"
          max="100"
          value="0"
          id="secondRange"
          style="display: none"
        />
        <input
          type="range"
          min="-100"
          max="100"
          value="0"
          id="thirdRange"
          style="display: none"
        />

        <button class="button yellow" onclick="sendActuatorData('FORWARD')">
          FORWARD
        </button>
        <button class="button red" onclick="sendActuatorData('STOP')">
          STOP
        </button>
        <button class="button blue" onclick="sendActuatorData('BACKWARD')">
          BACKWARD
        </button>
      </div>
      <div class="joystick">
        <div id="joystick-container">
          <div class="base"></div>
          <div id="stick1">
            <div class="stick1"></div>
          </div>
        </div>
        <div id="joystick-container">
          <div class="base"></div>
          <div id="stick2">
            <div class="stick2"></div>
          </div>
        </div>
      </div>
      <div class="claw">
        <h3>Claw</h3>
        <button class="button green" onclick="sendClawData('GRAB')">
          GRAB
        </button>
        <button class="button red" onclick="sendClawData('RELEASE')">
          RELEASE
        </button>
      </div>
    </div>
    <script>
      let servoBasePosition = 90;
      let servoSecondPosition = 90;
      let servoThirdPosition = 90;
      function sendActuatorData(actuatorStatus) {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function () {
          if (this.readyState == 4 && this.status == 200) {
            console.log(this.responseText);
          }
        };
        xhttp.open("GET", "setActuator?ActStatus=" + actuatorStatus, true);
        xhttp.send();
      }

      function sendClawData(clawStatus) {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function () {
          if (this.readyState == 4 && this.status == 200) {
            console.log(this.responseText);
          }
        };
        xhttp.open("GET", "setClaw?ClawStatus=" + clawStatus, true);
        xhttp.send();
      }

      function sendBaseServoData(baseStatus) {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function () {
          if (this.readyState == 4 && this.status == 200) {
            servoBasePosition = parseInt(this.responseText);
          }
        };
        xhttp.open("GET", "setBase?BaseServoStatus=" + baseStatus, true);
        xhttp.send();
      }
      var slider = document.getElementById("baseRange");
      slider.oninput = function () {
        if (slider.value != 0) {
          sendBaseServoData(this.value);
          if (servoBasePosition >= 180 || servoBasePosition <= 0) {
            document.querySelector(".stick1").style.backgroundColor = "#ff6347";
          } else {
            document.querySelector(".stick1").style.backgroundColor = "#4caf50";
          }
        }
      };

      function sendSecondServoData(secondStatus) {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function () {
          if (this.readyState == 4 && this.status == 200) {
            servoSecondPosition = parseInt(this.responseText);
          }
        };
        xhttp.open("GET", "set2Servo?SecondServoStatus=" + secondStatus, true);
        xhttp.send();
      }
      var slider2 = document.getElementById("secondRange");
      slider2.oninput = function () {
        if (slider2.value != 0) {
          sendSecondServoData(this.value);
          if (servoSecondPosition >= 180 || servoSecondPosition <= 0) {
            document.querySelector(".stick1").style.backgroundColor = "#ff6347";
          } else {
            document.querySelector(".stick1").style.backgroundColor = "#4caf50";
          }
        }
      };

      function sendThirdServoData(secondStatus) {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function () {
          if (this.readyState == 4 && this.status == 200) {
            servoThirdPosition = parseInt(this.responseText);
          }
        };
        xhttp.open("GET", "set3Servo?ThirdServoStatus=" + secondStatus, true);
        xhttp.send();
      }
      var slider3 = document.getElementById("thirdRange");
      slider3.oninput = function () {
        if (slider3.value != 0) {
          sendThirdServoData(this.value);
          if (servoThirdPosition >= 180 || servoThirdPosition <= 0) {
            document.querySelector(".stick2").style.backgroundColor = "#ff6347";
          } else {
            document.querySelector(".stick2").style.backgroundColor = "#4caf50";
          }
        }
      };
    </script>

    <script>
      class JoystickController {
        // stickID: ID of HTML element (representing joystick) that will be dragged
        // maxDistance: maximum amount joystick can move in any direction
        // deadzone: joystick must move at least this amount from origin to register value change
        constructor(stickID, maxDistance, deadzone) {
          this.id = stickID;
          let stick = document.getElementById(stickID);

          // location from which drag begins, used to calculate offsets
          this.dragStart = null;

          // track touch identifier in case multiple joysticks present
          this.touchId = null;

          this.active = false;
          this.value = { x: 0, y: 0 };

          let self = this;

          function handleDown(event) {
            self.active = true;

            // all drag movements are instantaneous
            stick.style.transition = "0s";

            // touch event fired before mouse event; prevent redundant mouse event from firing
            event.preventDefault();

            if (event.changedTouches)
              self.dragStart = {
                x: event.changedTouches[0].clientX,
                y: event.changedTouches[0].clientY,
              };
            else self.dragStart = { x: event.clientX, y: event.clientY };

            // if this is a touch event, keep track of which one
            if (event.changedTouches)
              self.touchId = event.changedTouches[0].identifier;
          }

          function handleMove(event) {
            if (!self.active) return;

            // if this is a touch event, make sure it is the right one
            // also handle multiple simultaneous touchmove events
            let touchmoveId = null;
            if (event.changedTouches) {
              for (let i = 0; i < event.changedTouches.length; i++) {
                if (self.touchId == event.changedTouches[i].identifier) {
                  touchmoveId = i;
                  event.clientX = event.changedTouches[i].clientX;
                  event.clientY = event.changedTouches[i].clientY;
                }
              }

              if (touchmoveId == null) return;
            }

            const xDiff = event.clientX - self.dragStart.x;
            const yDiff = event.clientY - self.dragStart.y;
            const angle = Math.atan2(yDiff, xDiff);
            const distance = Math.min(maxDistance, Math.hypot(xDiff, yDiff));
            const xPosition = distance * Math.cos(angle);
            const yPosition = distance * Math.sin(angle);

            // move stick image to new position
            stick.style.transform = `translate3d(${xPosition}px, ${yPosition}px, 0px)`;

            // deadzone adjustment
            const distance2 =
              distance < deadzone
                ? 0
                : (maxDistance / (maxDistance - deadzone)) *
                  (distance - deadzone);
            const xPosition2 = distance2 * Math.cos(angle);
            const yPosition2 = distance2 * Math.sin(angle);
            const xPercent = parseFloat((xPosition2 / maxDistance).toFixed(4));
            const yPercent = parseFloat((yPosition2 / maxDistance).toFixed(4));

            self.value = { x: xPercent, y: yPercent };
          }

          function handleUp(event) {
            if (!self.active) return;

            // if this is a touch event, make sure it is the right one
            if (
              event.changedTouches &&
              self.touchId != event.changedTouches[0].identifier
            )
              return;

            // transition the joystick position back to center
            stick.style.transition = ".2s";
            stick.style.transform = `translate3d(0px, 0px, 0px)`;

            // reset everything
            self.value = { x: 0, y: 0 };
            self.touchId = null;
            self.active = false;
          }

          stick.addEventListener("mousedown", handleDown);
          stick.addEventListener("touchstart", handleDown);
          document.addEventListener("mousemove", handleMove, {
            passive: false,
          });
          document.addEventListener("touchmove", handleMove, {
            passive: false,
          });
          document.addEventListener("mouseup", handleUp);
          document.addEventListener("touchend", handleUp);
        }
      }

      let joystick1 = new JoystickController("stick1", 64, 8);
      let joystick2 = new JoystickController("stick2", 64, 8);

      function update() {
        const clamp = (value, min, max) => Math.min(Math.max(value, min), max);

        const clampAndScale = (val) => {
          const scaled = val * -100;
          return clamp(Math.round(scaled), -100, 100);
        };

        const joystick1X = clampAndScale(joystick1.value.x);
        const joystick1Y = clampAndScale(joystick1.value.y);

        const joystick2X = clampAndScale(joystick2.value.x);
        const joystick2Y = clampAndScale(joystick2.value.y);

        const baseRangeInput = document.getElementById("baseRange");
        if (joystick1X >= 50) {
          baseRangeInput.value = 100;
        } else if (joystick1X <= -50) {
          baseRangeInput.value = -100;
        } else {
          baseRangeInput.value = 0;
        }
        var inputEvent = new Event("input", { bubbles: true });
        slider.dispatchEvent(inputEvent);

        const secondRangeInput = document.getElementById("secondRange");
        if (joystick1Y >= 50) {
          secondRangeInput.value = 100;
        } else if (joystick1Y <= -50) {
          secondRangeInput.value = -100;
        } else {
          secondRangeInput.value = 0;
        }
        var inputEvent = new Event("input", { bubbles: true });
        slider2.dispatchEvent(inputEvent);

        const thirdRangeInput = document.getElementById("thirdRange");
        if (joystick2Y >= 50) {
          thirdRangeInput.value = 100;
        } else if (joystick2Y <= -50) {
          thirdRangeInput.value = -100;
        } else {
          thirdRangeInput.value = 0;
        }
        var inputEvent = new Event("input", { bubbles: true });
        slider3.dispatchEvent(inputEvent);
      }

      function loop() {
        requestAnimationFrame(loop);
        update();
      }

      loop();
    </script>
  </body>
</html>


)=====";