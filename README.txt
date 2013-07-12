This module is Basic Koken Public API PHP implementation.

Koken is a free system designed for photographers, designers, and creative DIYs
to publish independent websites of their work.

It allows you to query, with the Views module, against a public Koken API.

Installation
------------

Install the koken module as any other drupal module.
This module need to grab datas from a Koken install, it won't do anything
if you don't use Koken.

See http://koken.me for more informations about Koken.

Documentation
-------------

The module provides a set of views query plugin and handlers.

To be able to query against a Koken install, you need to provide the koken uri
in the "Query settings" of the views (it is under the "advanced" column).

Quick note about the koken_example_views module.
------------------------------------------------

This example module provides 3 examples views.
- "Koken example album":
  This view display the public albums that are present in Koken.

- "Koken example content":
  This view should be use with an argument.
  - http://example.com/koken-example-content/[Album-ID]
    This will display all the picture that belongs to the Album-ID parameter

- "Koken example single content"
  - http://example.com/koken-example-single-content/[Content-ID]
    This is a page that display a single image grabbed from the Koken install.
    This page takes, as an argument, the content ID (image ID) that you want to display.
