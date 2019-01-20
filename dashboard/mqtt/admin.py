from django.contrib import admin
from .models import Sensors
#from django.contrib.auth.models import User, Group


# admin.site.unregister(User)
# admin.site.unregister(Group)


class SnippetAdmin(admin.ModelAdmin):
    list_display = ('topic', 'value', 'pub_date')
    list_filter = ('topic',  'pub_date')


admin.site.register(Sensors, SnippetAdmin)
admin.site.site_header = 'sammirkazemi@outlook.com'
admin.site.index_title = 'sam iot log system'
admin.site.site_title = 'sammirkazemi@outlook.com'
admin.site.disable_action('delete_selected')
