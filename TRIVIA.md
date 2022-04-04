# Trivia

This file holds the trivial parts of development process of this project, you can safely ignore it. This file exists so `me coding this thing` can feel more *personal*, more like *coding live streams* for you, if you're into that thing. You know what I am trying to say, I'm not very well versed in written language sometimes :/

PS: The commit messages and documents may have chaotic language, I'm not doing purple prose here, I just do my coding that way, think of live stream coding (but not in real-time and everything is in written language). This is a personal project after all, no need for 'politically correctness'. I may even cuss! If you're triggered by this, I'm not the right person for you.

# Apr 4 2022
- Trying to abstract the GL things, OpenGL can be major pain in the ass due to its state machine nature!
- I may need to revise the GL abstractions design, redo the *gl_abstract* thing from scratch.
- Tidy up the headers, *add the f'ing documentation before it is too late*. I'll basically have to do it if I want to add doxygen or whatever documentation generator I choose.
- Be very careful with the exception safety, it is as hard as debugging the code! (we're using C++ exceptions, to do away with littering the darn code with error checking everywhere)
- Refactor GL objects into a base class, they all are addressed by a GLuint (object name in GL terminology).
- When we'll have our first triangle displayed on the screen?
- Start by documenting *library_error.h* and *library_scope_guard.h*, they look very much done.
- Somehow abstract the vertex buffer structures too. Can get inspiration from (aka *copy the homework but make sure it is not too similar*) certain popular streamers...
- Am I doing this right?
- And there's developing the lore, composing the soundtrack, designing the *world* inside game, and somehow manage to do some digital art (aka *procedurally generate a metric ton of equations and vertices my way out*). Plotting the *art* like a *mathematical expression*. One of the core tenets of this game is procedural generation by the way, cause I suck at digital art. It looks like I'll complete my lifetime before this game :'D
- "Do everything by oneself, trying to prove oneself worthy... Say hello to your comrades in the moratorium..." Looks like a nice passage to add to the game.
- Prepare the channels for downloading the game easily when finished. The game's code and everything will always be open source, give people means to support the game at the final stages of development. Let this be a fully open source indie game from the start.
- Choose a license for the project.