from django.contrib import admin
#from django.contrib.auth.models import Group
from .models import Sensors


class SnippetAdmin(admin.ModelAdmin):
    list_display = ('topic', 'value', 'pub_date')
    list_filter = ('topic',  'pub_date')


admin.site.register(Sensors, SnippetAdmin)
# admin.site.unregister(Group)
admin.site.site_header = 'iot sensor dashboard'
admin.site.index_title = 'sam mirkazemi'
admin.site.site_title = 'salam :))'

admin.site.disable_action('delete_selected')
