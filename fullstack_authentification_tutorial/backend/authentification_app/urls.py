from django.urls import path
from . import views # needed to access/link the views (aka request handlers) to URLs of the app

# URL-view (aka request handler) mapping - like a dispatch table
urlpatterns = [
    path('sign_in/', views.auth_validation), # The first part of the URL that defines the app name is done by the urls.py of the django app
    path('sign_out/', views.auth_sign_out)
]