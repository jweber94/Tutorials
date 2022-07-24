# Fullstack user authentification with angular and JSON-Web-Token (JWT)
+ This tutorial is based on the [Angular 12 Login and Registration example with JWT & Web Api](https://www.bezkoder.com/angular-12-jwt-auth/)
+ The main differences are the following:
    * I want to implement the backend by using Python-Django and not with java spring boot
    * The user specific sites should have at least a little meaningful content

## Project Structure
+ TODO 

## Important notes
+ All requests to the backend needs to be validated at multiple points within the application to ensure its secure and correct function
    + Form-validation within the frontend code
    + Value validation within the business logic in the backend (to avoid malicious requests via `curl` or other http request generators)
    + Value validation while writing to the database to make sure that no mailicious code is delivered directly to the database and to make the checking more redundant