The goal is to simply search the house for two separate socks. 

Play a live demo here: https://repl.it/@byco/Sock-Search-Game

(Be sure to make the black terminal window on the right as wide as possible so the house map can be properly viewed, then click RUN at the top.)

GAME INTRODUCTION

The socks will be randomly placed in one or two random locations throughout the house. You may need to have the flashlight and/or the key in order to locate the socks; if the sock(s) are in the washing room, you need to find the flashlight first before entering the room, and if the sock(s) are in the closet, you need to find the key before accessing the closet.

Sadly, your house is a mess and you don’t have a clue where the key, flashlight or socks are (though for testing purposes, you know exactly where they are!).

The game either ends when you walk over 100 steps or find both socks.

Goal

	Find socks (2)

Game Play

	Sock #1, sock #2, flashlight, key to closet will be randomly placed
  
	Flashlight and key can only be placed in bedroom, lounge, kitchen, or bathroom (1-8)
  
		Possible locations (these numbers are used by the searchRoom function)
    
			1. Bedroom - under bed
			2. Bedroom - in drawer
			3. Bedroom - on floor
			4. Lounge - under sofa
			5. Lounge - on shoe shelf
			6. Lounge - on floor
			7. Kitchen - floor
			8. Bathroom - clothes hamper
			9. Closet
			10. Washing room - in washing machine
			11. Washing room - in dryer
			12. Washing room - on floor

Rooms (Spaces)

	Bedroom
	Closet
	Lounge
	Washing room
	Bathroom
	Kitchen

Space (parent class)

	Virtual (to be overwritten) functions
		Room menu (Print current location at the top)
			Explore menu
				Search options
			Move rooms
	Other functions
		Print map
		Check inventory

Interactions for each space

	(SEARCHES REQUIRE 5 STEPS EACH)
	Bedroom
		Search under bed
		Search drawer
		Search floor
	Closet
		Needs key in order to search
		Search
	Lounge
		Search sofas
		Search shoe shelf
		Search floor
	Washing room
		Needs flashlight in order to search
		Search washer
		Search dryer
		Search floor
	Kitchen
		Search floor
	Bathroom
		Search clothes hamper

Container (as much as you can hold in your hands - 3 items)

	Items include
		Key to closet (can be found in bedroom)
		One sock (need second sock to win)
		Flashlight (needed for washing room - has broken lightbulb)
		Two socks (GAME ENDS AS SOON AS 2 SOCKS ARE IN POSSESSION)

Game Ends

	Either when you find the socks
	Or time limit is reached (100 steps)

Print map

	Map of house
	Each room requires 10 steps to walk to next room


                          HOUSE MAP
----------------------------------------------------------------
|                   |                     |                    |
|     Bedroom               Closet        |    Washing Room    |
|     (start)             (needs key)     | (needs flashlight) |
|                   |                     |                    |
|------      -------------------------------------      -------|
|                   |                     |                    |
|     Bathroom              Lounge               Kitchen       |
|                                                              |
|                   |                     |                    |
----------------------------------------------------------------

