
![category](https://img.shields.io/badge/Category-Game_Development_--_2D_Graphics_--_Design_Patterns-blue)

![API](https://img.shields.io/badge/API-SFML-green)

![Language](https://img.shields.io/badge/Language-C++-purple)
# Game Patterns Visualizer

The goal of this project is to demonstrate mastery of different game patterns through concrete examples, as well as a preview. 
This project is based on Robert Nystrom's book [_Game Programming Patterns_.](https://gameprogrammingpatterns.com/) For the graphical elements, the SFML library is used. 
Each pattern attempts to solve a specific problem, so the demos will take the form of problem/solution for greater clarity.
### Environment 

```
Compilateur : MVSC
Standard C++ : C++17 
Build system : CMake 3.28+
```
### Designs Patterns

| Design Pattern                                                  | Description                                                                                                                                                                                                                                                                                                                                 | Class                | Status |
| --------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | -------------------- | ------ |
| [Command](https://gameprogrammingpatterns.com/command.html)     | The Command pattern can be defined by calling a method defined in an object. <br><br>**Demo**: The trolley problem, each player choice is a Command object stored in a history and visualized in real time.                                                                                                                                 | CommandPatternDemo   | ✔️     |
| [Flyweight](https://gameprogrammingpatterns.com/flyweight.html) | This pattern allows optimizing RAM usage by creating a Flyweight, which is a more or less heavy object that will be used multiple times. <br><br>**Demo**: A 2D map in which each tile has an extrinsic part (unique to the object) and an intrinsic part (shared between multiple objects). By clicking on a tile, we can see both states. | FlyweightPatternDemo | ✔️     |
| [Observer](https://gameprogrammingpatterns.com/observer.html)   | This pattern is used to notify of a change in the code without having to modify the implementation of the calling class. <br><br>**Demo**: A simple clicker where each click will notify the observer (UI) and we can see the modifications in real time.                                                                                   | ObserverPatternDemo  | ❌      |
| Prototype                                                       |                                                                                                                                                                                                                                                                                                                                             | PrototypePatternDemo | ❌      |
## Features

- [x] Graphical components
	- [x] 2D Animation
	- [x] Button
	- [x] Text Box
	- [x] Dialog Box
- [x] Main menu
- [x] Resource manager for loading content
	- [x] Image
	- [x] Text JSON
- [ ] Design Patterns visualization
	- [ ] Command
		- [ ] The player can make choices and undo them with buttons
		- [ ] Animation for the trolley
		- [ ] Animation for the character
		- [ ] Dialog box (description)
		- [ ] Each choice can be visualized
	- [ ] Flyweight
		- [ ] Visualization of the 2D Map
		- [ ] Clickable tiles
		- [ ] Show the Intrinsic state
		- [ ] Show the Extrinsic state
		- [ ] Dialog Box (description)
	- [ ] Observer 
		- [ ] Clickable element 
		- [ ] Animation Cookie
		- [ ] UI (Money, CPC, CPS)
		- [ ] Upgrades
			- [ ] Cookie per click
			- [ ] Cookie per second (Auto click)
		- [ ] Dialog Box (description)
		- [ ] Arrow to show observer
	- [ ] Prototype




