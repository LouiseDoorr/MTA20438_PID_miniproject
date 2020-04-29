# PIDminiproject

This Physical Interface Design Mini-project was a collaboration by MTA-20438 with the following members: 
- Dávid Gulyás 				          – Studienr.: 20184012
- Hamzah Ziadeh			            – Studienr.: 20183743
- Louise Dørr Nielsen 			    – Studienr.: 20183839
- Steffen Lehmann			          – Studienr.: 20153945
- Thomas Bendix Nielsen 		    – Studienr.: 20182727
- Thomas Kim Kroman Kjeldsen    – Studienr.: 20183944


All relevant material that is not the code is located in the projectMaterial folder. The items are as follows: 
- Circuit diagrams 
- Mapping tables
- Slide
- State diagram

Additionally, you can check out some video content:
- [Link to the video presentation](https://youtu.be/XCKGmWt0xH0)
- [Link to the raw video of the demonstration of the prototype](https://www.youtube.com/watch?v=KwtzAa93t0E)


[Link to the github](https://github.com/LouiseDoorr/MTA20438_PID_miniproject)

The Arduino program
---------------
The code is designed as a Simon says game where the user is required to react to four coloured LEDs, which lights up one at a time. To react to these, they have a joystick with four LEDs around it corresponding to the signifier LEDs. Additionally, a counter is there to display the amount of correct movements the user has performed. When they move the joystick towards a correctly coloured LED, the counter increments and a new signifier LED lights up. If they move the joystick incorrectly, nothing happens and the same signier LED keeps being lit until the user makes the correct movement.
When the user reaches 20 correct repetitions, all the LEDs will turn off, the counter will display “End” and the game is over.

