from django.shortcuts import render
from django.template import loader
from django.http import HttpResponse

from .models import Sensors


def index(request):
    return HttpResponse("Hello, world. You're at the polls index.")


def monitor(request):
    latest_light_value = Sensors.objects.order_by('-pub_date')
    template = loader.get_template('mqtt/index.html')
    context = {
        'latest_light_value': latest_light_value,
    }
    return HttpResponse(template.render(context, request))
