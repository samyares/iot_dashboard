from django.urls import path

from . import views

urlpatterns = [
    path('info', views.info, name='info'),
    path('', views.monitor, name='monitor'),
    path('log', views.monitor, name='log'),
    path('paho', views.paho, name='paho'),
]
