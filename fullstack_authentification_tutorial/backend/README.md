# Backend

## Development Setup
+ This project is developed with VSCode. Therefor, you can find the VSCode configuration files within the `.vscode/` folder of this repository

## Django basics
### Installing Django
+ Installing Django by pip3 by typing (ideally within a separate virtual python environment)
```
$ pip3 install django
```
+ This will install the django python packages as well as the ``django-admin` CLI

### Createing a new Django project
+ Createing the project: 
```
$ django-admin startproject <name_project> . 
```
#### Explainations of the repository structure of a django project
+ `authentification_backend/__init__.py`: Tells the python interpreter to use the project filder as a package
+ `authentification_backend/settings.py`: Definition of the application settings
+ `authentification_backend/urls.py`: Definition of the endpoints of the application (aka our endpoints)
+ `authentification_backend/asgi.py` & `authentification_backend/wsgi.py`: Used for deployment
+ `manage.py`: Provides the django admin terminal interface with the project settings. We can call `$ python3 manage.py <command>` to work with our django backend

## Adding a new custom app to the django project
+ Each app provides a separate functionallity to our django project as a whole
+ Use the terminal interface by typing
```
$ manage.py startapp <name_of_the_app>
```
, to add a new app to the current django project
+ Everytime we create a new app on our project, we need to add it to the main project `settings.py`

### Django Apps
+ Every Django project contains of one or more Django apps 
+ Django comes with different basic apps. You can install additional ones but the default apps come with every django application
+ Every self written django app has the same folder and file structure
#### Django app structure
+ `views.py`: A view is a program/function that receives a request, do some business logic and then return a request. It is basically a request handler. 
    - On its own, it is ***NOT*** linked to a specific URL, it is without linking to URL a plain function with an I/O relation
+ Mapping an URL to a view
    - We need to create a url mapping function
    - Therfore we need to add a file which is by convention called `urls.py` for the individual app
        * Within this `./app/urls.py` we need to define the _relative_ URL to the projects URL, since the apps `urls.py` is called from the django projects `urls.py`. See `authentification_backend/urls.py` for details. Pay attention to `path('authentification_app/', include('authentification_app.urls'))` and the instructions in the comments

#### Django Model classes
+ Model classes are used to model, store and retrieve data in our backend
+ Each django app has its own data model
    - Django apps should follow the Unix/Posix Philiosophy: Each program should do just one thing, and this one thing should be done well
+ Models in Django are classes that represent a table within a database
    - Each datatype is represented as its own model
    - Each model mapts to a single table within a database
    - Models can be used to add or retrive data from/to a database
+ After the data is modeled by the model class, it must be migrated to a database

##### Data Modeling
+ As a first step, we need to figure out, what data we need to store in our backend
+ We need to also model the data relationships
    * One-to-One
    * One-to-Many
    * Many-to-Many

### Run the dev server from terminal (without launch.json in VSCode)
+ After defining the project settings, we can run the dev server by invoking 
    - `$ python3 manage.py runserver 8081`

### Debugging Django project
+ Besides the common VSCode (or your favourite IDEs Python Debugger), Django delivers a convenience tool for getting to know some statistics about the backend
    - See [Django Debug Toolbar in the video](https://www.youtube.com/watch?v=rHux0gMZ3Eg)

## References
+ [Django Tutorial](https://www.youtube.com/watch?v=rHux0gMZ3Eg)
+ https://www.bezkoder.com/angular-14-jwt-auth/
+ Django models: 
    - https://www.geeksforgeeks.org/django-model-data-types-and-fields-list/
    - https://www.youtube.com/watch?v=5zNR3E6WRLE
+ Django migration
    - https://www.youtube.com/watch?v=aOLrEkpGWDg

# ToDos
+ Add another app to work with the user data
    - Concept: 
        * Use the `authentification_app` for the exchange of the JWT
        * The `user_data_app`(unimplemented yet) should be used to exchange the user data from the backend to the frontend    