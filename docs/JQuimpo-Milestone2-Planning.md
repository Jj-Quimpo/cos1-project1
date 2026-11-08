> Use this worksheet to plan the next phase of your project **before you begin coding**
> Be clear, specific, and intentional—this will guide your development this week.

---
## 📌 Project Overview

**Project Name:**
→   Cockroaches Tale: The Kitchen Wall
  
**What does your program currently do? (1–3 sentences)**   
→ The program is able to keep the main menu running with a While loop until the user inputs one of the selections available. In the dungeon part of the code the player can have different scenarios happen and is able to make choices and either be rewarded or suffer. During the rat ambush it is a turn based fighting giving the user a chance to either attack, defend, or flee.

---
## 🔍 Current Progress Check  
  
**What is working right now?**   
→   At the moment everything is working fine and running as it should. 
  
**What is NOT working or incomplete?**   
→   The rat ambush is not complete it is turn based but the rat attacks are more like follow-ups instead of an actual turn to turn fight. With the lack of Items to boost attack or heal it feels empty.
  
**What feels confusing or messy in your code?**   
→ Dungeon feels messy it feels hard to discern what is what so it definitely needs more organizing.

---
## 🚀 Feature Planning  
  
List the features you plan to add or improve this week.  
  
### Feature 1  
**Name:**   
→   Improve the Combat System.
  
**What does this feature do?**   
→   This is what handles the turn based fighting.
  
**Why is this feature important?**   
→   This is to keep the game engaging for the user throwing an obstacle and force the player to plan their next move.
  
---
### Feature 2  
**Name:**   
→   Merchant
  
**What does this feature do?**   
→   This will allow the player to spend their crumbs and help them with their encounters with rats.
  
**Why is this feature important?**   
→   This can help the players run allowing them to reach farther levels, and put the player into the position of keeping track of their spending.
  
---
  
### Feature 3 (optional)  
**Name:**   
→   Healing
  
**What does this feature do?**   
→   allow 
  
**Why is this feature important?**   
→   To keep the player alive during their run.
  
---
## 🧩 System Design Updates  
  
**Will you need to create any new classes? If so, which ones?**   
→   Yes I would need to make a merchant class, and possibly a rat type class, as well as a item class for damage and healing.
  
**Will you modify any existing classes? How?**   
→   Yes, because everything is within the dungeon class, it is gonna need to be modified to include all the new classed and new scenarios.
  
**What data structures will you use (vectors, 2D vectors, etc.)?**   
→   many vectors will be created as well as many loops like if, else-if, and while loop.
  
---
## 🔄 Program Flow  
  
**Describe how a user interacts with your program:**  
  
1. Program starts →   Menu shows giving the options of 1 start journey/game, or 2 exit game
2. User chooses →  player types 1 or player types 2 must be integer or the choice counts as invalid.
3. Program responds →   If player types 1 it starts the game, player chooses 2 exits the console/program.
4. Loop/next step →   1 keeps the while loop going and starts the loop from dungeon, 2 stops the loop completely.
  
---
## 🎯 Usability Improvements  
  
How will you make your program easier to use this week?  
  
- Clearer prompts:   
→   A tutorial/disclaimer telling the user how to make a selection.
  
- Better error handling:   
→   prompts an error message if they typed something other than the required input.
  
- Improved menu/navigation:   
→   Make sure the menu is listed correctly
  
---
## ⚠️ Potential Challenges  
  
**What do you think will be the hardest part this week?**   
→   The combat system.
  
**What is your plan if you get stuck?**   
→   Break it down into pieces that I can do and move onto the next task.
  
---
  
## 📈 Level Up Goal  
  
**What skill are you focusing on improving this week?**   
→   improve using vectors
  
**What will you do to improve it?**   
(e.g., tutorial, practice, debugging, office hours)   
→   practice using vector by creating an inventory and on the side.
  
---
## 🗓️ Task Breakdown (GitHub Issues Planning)  
  
List the tasks you plan to create as GitHub Issues:  
  
- [x]   Improve the combat system
- [x]   Add different type of rats
- [x]   Create a Tutorial
- [x]   allow multiple choice to have different outcomes
  
---
  
## 🔥 Final Check  
  
Before you start coding, ask yourself:  
  
- [x] Do I know what I’m building this week?   
- [x] Do I know where to start?   
- [x] Did I break my work into small tasks?   
  
If yes → start coding 🚀   
If no → refine your plan first   
  
---
## 😈 Final Thought  
  
> With the combat system implemented I should pave a easier path when I start to add more feature as it would mostly add onto the combat system and/or to the dungeon more than having to create a whole new system.