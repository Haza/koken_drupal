<?php

/**
 * @file
 * Defines a basic field handler to display information about the album.
 */

/**
 * Field handler to display a basic text field.
 */
class koken_handler_album_generic_field extends views_handler_field {

  // Used to keep field_alias synched with field name.
  function query() {
    $this->field_alias = $this->real_field;
  }

}
