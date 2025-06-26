--------------------------------My Journey-------------------------------


- Making a new int, already had to google operator overloading.
    - Found out I need to pass in a reference to the object and return a pointer to the address.

- Must make an initialization for "Test num = 5" to work vs "Test num; num = 5;"

- Thought of theme with dwarves and runes, Warhammer fantasy based.
    - Used ChatGDP to help brainstorm naming and ideas.
    - Changed idea to League of Votann (sci-fi dwarves).

- Confused on how to start with CPU, watched a video and had ChatGDP explain some concepts and ideas to get started.
    - DataCores are the actual values being used and stored.
    - ProcessorNodes hold and manipulate the DataCores.
    - VotannCPU is, well, the CPU—manages and instructs the nodes.

- Talked to professor for guidance—recommended working on the basics of how the memory will work.
    - Going to use a stack. Seems like it literally works like a memory stack.

- Working on CPU instructions using ChatGDP for some guidance moving forward—got stuck on some instructions.
- Gonna use a node pointer to easily access each ProcessorNode // Register.
- Got BIND, FORGE, BURN, SMELT done.
- Confused on CMP. ChatGDP helped, made a struct with bool flags.

- Split current file into multiple header files, got a weird error with multiple mains being declared. Guess you can only have one int main() throughout all the files lol.

- Decided to split up instructions since it bloated VotannCPU, moved into own file as a namespace. Lots of weird errors started showing up. ChatGDP and Google helped resolve and restructure code to fit this.

    - Issue with flag structure for JUDGMENT, had to make it static. Did some fun renaming!

- Issues with CoreBank working in runes, looked into a way to make CoreBank created once and usable throughout the program (since it's the memory stack). Learned about `extern`.

- Got lazy with making both .cpp and .h files. Had ChatGDP help quickly format each one from the code I wrote. It already messed up formatting, have to go back and manually clean it :(

- Finished separating compilation files so everything works, split up a lot to make it cleaner. ChatGDP helped format my code to fit .h and .cpp (also added helpful comments).

- Weird compile issues with cores.h, not compiling or something.
    - Made new projects and added/linked files one at a time. Seems like a weird file compile/linking issue. Probably should’ve done the split compilation sooner.

- Not sure what the issue was in the end—went through a few things but ended up manually linking files via command console. Some error with Dev C++ from what I understand. Just glad it's over.

- Noticing issues with SMELT (POP). Guess stack.top just passes a reference instead of copying the value itself.
    - Added if statements to help logic when memory stack is empty.
    - Renamed to CraftCore since there’s already a FORGE command.

- Moved on to making a custom int variable called Stonebit, just altered my Test class from another project. Want to make it so you're only ever using Stonebits, not actual ints. Had an okay version with some weird logic errors. Got annoyed, was taking too long, so ChatGDP helped fix it.

- Got math operators to use the CPU and register correctly. Looking into doing the same with comparison operators, but too much restructuring for now. Maybe in the future.

- Brain hurts, pushed through making the comparison operator stuff. Annoying.
    - Had to use ChatGDP for help. Turns out you must make functions that return verdicts. Recommended to make it const and pass by reference for secure data.

- Took a break from template stuff, made JUDGE simpler.

- Got data types to work using a Bits template, and from that, made child classes that inherit and represent other data types. Had issues with assigning them using `=`, but ChatGDP helped by creating a converter from `Bit<T>` to the corresponding child class.

- This has been a lot. I feel like if I started earlier, I could’ve relied on AI and others' code less, but the fact these resources were available helped push this project beyond my skill level and taught me things like `extern`. I'm happy with the current version and can see this expanding further.

- Found out you can’t iterate through a stack container. Learned how to make a copy, display the top, and pop to the next.

    - Turns out the bigger problem was the memory stack wasn’t even being used.

- Okay, did memory kind of wrong, was only using it with CPU. Professor (thanks!!) gave a great idea: try using maps and IDs.

- Got the DataLog map working. Turns out having lots of separate files and needing stuff from other files is super annoying and confusing. After experimenting with `#includes` and reading error messages, I got it working, just for Keystone. The other data types can wait for now.

- Wanted to make a fun calculator, gonna use try-catch for one of the functions... also so much more work. I keep doing this to myself lmao.

- Back to DataLog, want to make it work with removing Keystone from the stack, now using pointers!
    - Okay, it’s going to take way too long for this, going back.

- Working on the actual program. Looks cool with all the naming!
    - Used ChatGDP to make the cout stuff sound cool and thematic.

- Did some tweaks just to get the program working. In the end: memory works (both DataLog and stack), CPU and registers work. Lots more to do, but damn, it's done. (For Now)
