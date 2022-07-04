# Introduction to ReactiveX
+ Based on the Tutorial [](https://www.youtube.com/watch?v=PhggNGsSQyg)

## Setup of the basic node project with yarn
+ "yarn" is an alternative package manager for javascript, developed by facebook
+ Installation: [](https://linuxize.com/post/how-to-install-yarn-on-ubuntu-20-04/)

### Starting the project
+ Init the project with ```$ yarn init -y```
+ Install dependencies: ```yarn add typescript tsloader webpack webpack-dev-server rxjs```
+ Install development dependencies (which are not get deployed): ```yarn install webpack-cli --dev```
+ On every yarn project, we have a `package.json` within which we can define dependencies (which get resolved on purpose) and scripts. 
    - Scripts define what should be executed if we type ```$ yarn run <script-name>```
#### Further `yarn`
+ Removing package from the project: `$ yarn remove <package_name>`
+ Installing packages from the `package.json`: ```$ yarn install # from within the folder where the package.json is```