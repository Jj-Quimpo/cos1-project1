# Instructions

Update this document where indicated [look for the brackets!]. Replace text inside the brackets with your own information. For example: Course Name should be the name of this course, and not the generic words "Course Name".

<br>

## [ COS119-O]

- **[ Jerome Quimpo-Duque ]**
- **[ Nov 1, 2026]**

This paper addresses some of the topic matter covered in research and activity this week. Be sure to include reference links below to the research and information you used to complete this assignment.

## Topic: Terminal

Professional developers use Terminal daily. It's essential to understand some fundamental commands to use the application.

Update the information below to demonstrate your knowledge on this topic.

**1. Using Terminal, there are essential commands to know.**

List the correct Terminal commands to do the actions listed below. Replace **CMD** with the correct command sequence. You can keep or enhance the brief description.

**The last bullet provides an example**.

- [ clear ]: Clear the Screen
- [ pwd]: Print the "Working Directory"
- [ Is]: List files and folders
- [ Is -a]: List files and folders, including invisible files
- [ Is -Ih]: List all files and folders, in human readable form
- [ cd [folder]]: Change directory
- [ cd / ]: Change directory, go to root directory
- [ cd or cd~]: Change directory and go to user home directory
- [ cd .. ]: Change directory, go up one folder level
- [ cd ../..]: Change directory, go up two folder levels
- [ cd Desktop]: Change directory to my desktop!

**2. Using Terminal...**

**Folder Drop:** Try typing "cd" followed by a space, and then drag a folder into terminal and press return. Test this out and describe your results below.

[ when I did cd and dragged the folder into the terminal it copied the path of the folder and changed the directory to that said folder path. ]

## Topic: Version Control & Git

Version control, also known as revision control, records changes to a file or set of files over time so that you can recall specific versions later. In this class, we are learning Git. Update the information below where indicated.

**1. There are three types of version control.**

[ Local : saving/copying a file from one directory to another or with a new version number, simple but leaves room for errors. Centralized (CVCS): utilized when developers need to collaborate on a single server, a developer checks out the recent code and works on what needs to be completed, problems are if the server goes down everything is lost besides small snippits. Distributed(DVCS): Allows a developer to make an exact copy and save it onto a local drive, if the server goes down each copy a developer has can be used as a backup. DVCS can handle several remote repos and allows developers to work in groups.]

**2. Using Terminal, there are also essential Git commands to know.**

List the correct Git commands to do the actions listed below in Terminal. Replace CMD with the correct command and keep or enhance the brief description.

- [ git clone [url]]: Clone a repository
- [ git config --global user.name "[Firstname Lastname]"]: Set-up a global user name
- [ git config --global user.email "[valid email]]: Set-up a global email address (to match my GitHub account email)
- [ git status]: Shows the current state of your directory and staging area
- [ git add ]: Add modified files to the next commit
- [ git commit -m "[descriptive message]"]: Make a commit with a new message
- [ git log]: Show my commit history
- [ git help]: Show Git's help screen

**3. Connecting to GitHub using Terminal.**
HTTPS is the the correct way to connect to GitHub in this course. Describe how you connect to GitHub from Terminal using this protocol. What steps do you take?

[ first you would want to get the url from GitHub, inside the terminal you want the  path of the folder you want to clone your repo into from there clone the repo with git clone "repo url".]

**4. Using .gitignore and Why it's Important**  
Most repositories contain a .gitignore file.

- What is the purpose of this file?
  <br>
  [Prevents tracking of unnecessary and or sensitive files, helps keep the repository clean.]

- What is the "**.DS_Store**" file and why would you want to ignore it?
  <br>
  [.DS_Store is a file that contains finder specific view preferences. It is harmless but it is best left alone because it can cause issues for Git especially when you try to commit.]

- What other file or folder would you want to add to a .gitignore file and why?
  <br>
  [You want to add local, sensitive, and unnecessary files to the .gitignore so you can avoid cluttering you repository and git history when sharing a project with others.]

<br>

# Reference Links

Replace the example references below with your own links and recommended resources. It is acceptable to provide multiple links for a single topic and to use material provided to you in this class. You are encouraged to link to your own independent research as well.

[ I never really knew about the commands you can use inside the terminal and it was very informational on how I can access clone and commit to Git from the terminal itself. ]

**Terminal Commands**  
[terminal-mac-cheatsheet]([0nn0/terminal-mac-cheatsheet: List of my most used commands and shortcuts in the terminal for Mac](https://github.com/0nn0/terminal-mac-cheatsheet#english-version))

**Three Types of Version Control**  
[Version Control from the class](https://www.someaddress.com/full/url/)

**Git Commands**  
[GitHub Git Cheat Sheet]([git-cheat-sheet-education](https://education.github.com/git-cheat-sheet-education.pdf))

**Connecting to GitHub using Terminal**  
[GitHub Docs Set Up Git]([Set up Git - GitHub Docs](https://docs.github.com/en/get-started/git-basics/set-up-git))

**Using .gitignore and Why it's Important**  
[W3 schools Git Ignore and .gitignore]([Git Ignore and .gitignore](https://www.w3schools.com/git/git_ignore.asp))
