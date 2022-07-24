from django.db import models

# Create your models here.
class UserData(models.model): # inherit data from the models.model class that is an abstract base class delivered by django
    # django model data: https://www.geeksforgeeks.org/django-model-data-types-and-fields-list/
    first_name = models.CharField(max_length=20)
    last_name = models.CharField(max_length=20)
    email = models.CharField(max_length=30)
    password = models.CharField(max_length=12)
    creation_data = models.DateTimeField(auto_now_add=True)