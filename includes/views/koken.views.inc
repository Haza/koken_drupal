<?php

/**
 * @file
 * This file include all the Views hook implementations.
 */

/**
 * Implements hook_views_plugin().
 */
function koken_views_plugins() {
  return array(
    'module' => 'koken',
    'query' => array(
      'koken_query_plugin' => array(
        'title' => t('Query from Koken api'),
        'help' => t('Using a PHP array as data source.'),
        'handler' => 'koken_query_plugin',
        'parent' => 'views_query',
      ),
      'koken_query_plugin_albums' => array(
        'title' => t('Query Albums from Koken api'),
        'help' => t('Using a PHP array as data source.'),
        'handler' => 'koken_query_plugin_albums',
        'parent' => 'koken_query_plugin',
      ),
      'koken_query_plugin_content' => array(
        'title' => t('Query content from Koken api'),
        'help' => t('Using a PHP array as data source.'),
        'handler' => 'koken_query_plugin_content',
        'parent' => 'koken_query_plugin',
      ),
    ),
  );
}

/**
 * Implements hook_views_data().
 *
 * Making the option appear as a view type requires implementing
 * hook_views_data().
 *
 * With the field, we are defining how this item must be handled, but we have to
 * declare first the type of handler we are talking about. We may have different
 * handlers for each field, and we may use views default handlers or our custom
 * ones.
 */
function koken_views_data() {
  $data['koken_albums']['table']['group']  = t('Koken Album');
  $data['koken_albums']['table']['base'] = array(
    'title' => t('koken API - Albums'),
    'help' => t('Use koken REST API..'),
    'query class' => 'koken_query_plugin_albums',
  );
  $data['koken_albums']['title'] = array(
    'title' => t('Album Name'),
    'help' => t('Get the album name.'),
    'field' => array(
      'handler' => 'koken_handler_generic_field',
    ),
  );
  // Define a summary field.
  $data['koken_albums']['summary'] = array(
    'title' => t('Album Summary'),
    'help' => t('Display the album summary.'),
    'field' => array(
      'handler' => 'koken_handler_generic_field',
    ),
  );
  // Define a description field.
  $data['koken_albums']['description'] = array(
    'title' => t('Album description'),
    'help' => t('Display the album description.'),
    'field' => array(
      'handler' => 'koken_handler_generic_field',
    ),
  );
  // Define an cover field.
  $data['koken_albums']['cover'] = array(
    'title' => t('Album Cover'),
    'help' => t('Get the album cover.'),
    'field' => array(
      'handler' => 'koken_handler_album_cover_field',
    ),
  );
  // Define a tag field.
  $data['koken_albums']['tags'] = array(
    'title' => t('Album tags'),
    'help' => t('Get the tags.'),
    'field' => array(
      'handler' => 'koken_handler_tags_field',
    ),
  );

  $data['koken_content']['table']['group']  = t('Koken Content');
  $data['koken_content']['table']['base'] = array(
    'title' => t('koken API - Content'),
    'help' => t('Use koken REST API..'),
    'query class' => 'koken_query_plugin_content',
  );
    // Define an id field.
  $data['koken_content']['id'] = array(
    'title' => t('Content id'),
    'help' => t('Get the content id.'),
    'field' => array(
      'handler' => 'koken_handler_generic_field',
    ),
    // Information for accepting a aid as an argument
    'argument' => array(
      'handler' => 'koken_handler_argument_cid',
      'name field' => 'Content ID',
      'numeric' => TRUE,
    ),
  );
  // Define an id field.
  $data['koken_content']['aid'] = array(
    'title' => t('Content album id'),
    'help' => t('Get the album id.'),
    'field' => array(
      'handler' => 'koken_handler_generic_field',
    ),
    // Information for accepting a aid as an argument
    'argument' => array(
      'handler' => 'koken_handler_argument_aid',
      'name field' => 'Album ID',
      'numeric' => TRUE,
    ),
  );
  // Define a image field.
  $data['koken_content']['image'] = array(
    'title' => t('Image'),
    'help' => t('Get the content picture.'),
    'field' => array(
      'handler' => 'koken_handler_content_image_field',
    ),
  );
  // Define the exif field.
  $data['koken_content']['exif'] = array(
    'title' => t('Exif informations'),
    'help' => t('Get the exif informations.'),
    'field' => array(
      'handler' => 'koken_handler_content_exif_field',
    ),
  );
  // Define the title field.
  $data['koken_content']['title'] = array(
    'title' => t('Title'),
    'help' => t('Get the title.'),
    'field' => array(
      'handler' => 'koken_handler_generic_field',
    ),
  );
  // Define the caption field.
  $data['koken_content']['caption'] = array(
    'title' => t('Caption'),
    'help' => t('Get the caption..'),
    'field' => array(
      'handler' => 'koken_handler_generic_field',
    ),
  );
  // Define the tags field.
  $data['koken_content']['tags'] = array(
    'title' => t('Tags'),
    'help' => t('Get the tags.'),
    'field' => array(
      'handler' => 'koken_handler_tags_field',
    ),
  );
  return $data;
}
