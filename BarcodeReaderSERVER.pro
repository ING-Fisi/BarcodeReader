TEMPLATE = subdirs

SUBDIRS = library \
          application

library.subdir = datepicker_library
application.subdir = BarcodeReader

application.depends = library
