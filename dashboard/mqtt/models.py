from django.db import models


class Sensors(models.Model):
    topic = models.CharField(max_length=50)
    value = models.CharField(max_length=10)
    pub_date = models.DateTimeField('date published', blank=True, null=True)
