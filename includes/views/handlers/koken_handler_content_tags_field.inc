<?php

/**
 * @file
 * Defines a basic field handler to display information about the album.
 */

/**
 * Field handler to display a basic text field.
 */
class koken_handler_content_tags_field extends views_handler_field_custom {

  // Used to keep field_alias synched with field name.
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
    return theme('item_list', array('items' =>$values->tags));
  }
}
