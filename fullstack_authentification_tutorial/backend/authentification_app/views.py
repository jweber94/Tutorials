from django.shortcuts import render
from django.http import HttpResponse

# Create your views (Request Handler) here.
def auth_validation(http_request):
    # Here we can do whatever we want to do in case the request was send to us from the client
    print("Signing in")
    return HttpResponse("Success")    

def auth_sign_out(http_request):
    print("Signing out")
    return HttpResponse("Signed out")