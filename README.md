#	Asteroids

CPSC 462; Group Project

*	Mike Peralta mikeperalta@csu.fullerton.edu
*	Eric Guzman striderkills@gmail.com
*	Alessandro Quezada sandroq95@csu.fullerton.edu

#	Windows - Building and Running

The repo contains a folder "visual-studio-projects" which inside *should hopefully* contain projects you can simply open, but we have no idea if this will work for you (Professor), so here are the steps we took to create working VS projects:

**Steps must be repeated once for the Server executable, and once for the Client executable**
(and you may have to "rescan" the project after applying these settings)

1. Create an Empty Project (Visual C++ ==> Empty Project) and name it either "Asteroids Server" or "Asteroids Client"

2. Drag + Drop the source code folder "Asteroids" directly onto the VS Solution root in the Solution Explorer pane. If it worked, you should see a bunch of source files show up.

3. In the project's properties, under "C/C++" => "General" => "Additional Include Directories", add the directory *just above* the Asteroids source folder as an include path (ie: the main repo folder). So for instance, if the repo folder's name is C:\Elaboration1 (thus there exists the path C:\Elaboration1/Asteroids), then you'd need to add C:\Elaboration1 as an additional include directory

4. In the project's properties, under "C/C++" => "Output Files" =>  "Object File Name", change "$(IntDir)" to "$(IntDir)/%(RelativeDir)". This is because some source files have the same name, thus VS needs to generate objects that include their relative directory in the name, so the objects won't collide with each other

5. Then, depending on whether this project intends to build the Server or the Client, you'll need to exclude either Asteroids/Executables/server.cpp or Asteroids/Executables/console-client.cpp because they both contain a reference to main(). You can do this by right clicking on the file, selecting "Properties", then "General", then select "Yes" for "exclude from build"

At this point you should be able to run with the windows "local debugger" option in VS

Don't forget to maximize your console window if you intend to play the game (hint: spacebar shoots, and will show you where your ship is)


#	Linux - Building and Running

## Show Help
1. Navigate inside the Asteroids directory
2. Execute make to see help:
	
	* ```make```

*	```make all``` to build everything
*	```make docs``` to build documentation
*	```make run-console-client``` to build+run the client executable
*	```make run-server``` to build+run the server executable


#	Generating and Viewing Docs

As of Oct 23, 2018, docs will automatically be uploaded to the hoth.sevencode.com main server:

*	http://hoth.sevencode.com/

Note that this is different from the main GOGS url, which is https://hoth.sevencode.com:3000

**You may still build docs manually if you want:**
1. Navigate to the src directory
2. Build docs with ```make docs```
3. Look inside the *docs/html* directory for the file *index.html*
4. Drag *docs/html/index.html* onto your browser
5. Enjoy like ... looking at the docs... or something

Doc generation *will succeed*, but will throw an error afterward if run by anyone other than Mike. This is because only Mike has permission to upload directly to hoth, until a better solution is found.
