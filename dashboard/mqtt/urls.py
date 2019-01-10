from django.urls import path

from . import views

urlpatterns = [
    #  path('/test', views.index, name='index'),
    path('', views.monitor, name='monitor'),
]
