## Affordable-multi-trigger-alert-system-for-household-events-for-deaf-and-heard-to-hear
The device acts as an "extra set of ears" by listening for important sounds around the house and alerting the wearer through tactile vibrations. It is specifically designed to be affordable and easy to use in environments where high-end assistive technology might be too expensive or complex.


## Project overview


The goal of this project is to bridge the "auditory gap" in a household environment by converting critical sound-based cues into tactile feedback. Many individuals with hearing impairments face daily safety and social challenges when missing ambient signals like emergency alarms or a simple knock at the door.This system is designed as a standalone, offline solution to ensure maximum reliability and privacy. By bypassing the need for smartphones or cloud connectivity, the device remains functional in areas with poor internet or for users who prefer non-digital complexity. It focuses on high-utility detection and intuitive vibration "languages" to restore a sense of awareness and security within the home.

## Critical Environmental cues


CCategory,Event Trigger,Impact of Missing the Event
Safety,"Smoke/Fire Alarms, Gas Leak Detectors",Immediate physical danger; life-threatening.
Security,"Doorbell, Door Knock, Glass Breaking",Potential security breach or missed visitors/deliveries.
Domestic,"Baby Cry, Microwave Beep, Telephone Ring",Interruption of caregiving or daily household flow.ues


## System Architecture

1. Sensor Integration (The "Ears")
Acoustic Sensors: High-sensitivity microphones tuned to specific frequency ranges (e.g., the high-pitch frequency of a smoke detector).

Vibration/Shock Sensors: Placed on door frames to detect physical knocking without relying on sound alone.

Gas/Smoke Sensors: Dedicated MQ-series sensors for direct environm2. Processing & Feedback (The "Touch")
The heart of the system is a low-power microcontroller (such as an Arduino or ESP32 variant) that processes raw sensor data.

Offline Logic: Signal processing happens locally on the chip using threshold analysis.

Haptic Mapping: The wearable unit uses a vibration motor to produce distinct "pulses."

Example: A long, continuous vibration for Fire vs. two short bursts for a Door Knock.

Phase 3: Prototyping & User Validation
The final stages move from the breadboard to the real world:

Form Factor: Transitioning the receiver into a comfortable wristband or clip-on device.

Reliability Testing: Ensuring the sensors do not trigger "false positives" from common background noises like a television or a falling object.

User Feedback Loops: Testing the "vibration vocabulary" with users to ensure the patterns are easy to memorize and distinguish under stress.ental monitorin <img width="1024" height="575" alt="image" src="https://github.com/user-attachments/assets/e227c83d-0dfc-4f23-84a2-d65b7c661098" />
Input $\rightarrow$ Digitize $\rightarrow$ Compare to Patterns $\rightarrow$ Trigger Haptics $\rightarrow$ Wireless Broadcast


## what problem it is solving

Emergency Response Gap: Eliminates the risk of missing life-threatening signals like smoke or gas alarms, especially during sleep.

Social Isolation: Prevents missed visitors or deliveries by providing an instant notification when the door button is pressed.

Visual Dependency: Solves the "line-of-sight" problem where flashing light alerts are useless if the user is in a different room or has their back turned.

Connectivity Barriers: Removes the need for expensive smartphones, apps, or stable internet, making the system reliable during power outages or in rural areas.

Privacy & Security: By using a local nRF24L01 radio link, no personal data is sent to the cloud, protecting the user's home privacy.

Economic Accessibility: Provides a low-cost alternative to expensive, medical-grade assistive technologies that many cannot afford.

Situational Awareness: Restores a sense of independence and security by keeping the user "connected" to their environment 24/7.

## how the system work

Step 1: Power On
Flip the House Mode switch to turn on the system.

This also powers up the wearable alert device.

Wait about one minute for the wearable to fully connect.

Step 2: Baby Cry Detection
The sound sensor is activated first.

If it detects a baby crying:

It turns on a motor that drives a buzzer on the arm.

The buzzer then triggers a blue LED light.

The blue light stays on for a preset duration chosen by the user.

Step 3: Smoke Detection
Next, the smoke sensor is switched on.

If smoke is detected:

A vibration motor is activated.

A red LED light turns on.

Because smoke is critical, the red light and vibration run for a longer time.

You can stop this alert by pressing the acknowledge button, which resets all sensors.

Step 4: Turning Off
If the person wants to rest or sleep, they can simply switch off House Mode.

This action shuts down the wearable system and all sensors.

✅ Summary
The system works in a clear sequence:

Power on → wearable connects.

Sound sensor → buzzer + blue light.

Smoke sensor → vibration + red light.

Acknowledge button → stop alerts.

Main switch → turn everything off.














