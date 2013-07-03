<?php

/**
 * @file
 * Defines a basic field handler to display information about the album.
 */

/**
 * Field handler to display a basic text field.
 */
class koken_handler_content_exif_field extends views_handler_field_custom {

  /**
   * Keep field_alias synched with field name.
   */
  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
    $this->field_alias = $this->real_field;
  }

  /**
   * The class contructor.
   */
  public function construct() {
    parent::construct();
    $this->additional_fields['data'] = 'data';
  }

  /**
   * Renders the handler.
   *
   * @param array $values
   *   View's values.
   *
   * @return string
   *   Renders the return reason.
   */
  public function render($values) {
    $output = '';
    foreach ($values->exif as $exif) {
      $value = isset($exif->clean) ? $exif->clean : $exif->raw;
      $output[] = $exif->label . ': ' . $value;
    }
    return theme('item_list', array('items' => $output));
  }
}
