<?php

/**
 * @file
 * Provide album id aid argument handler.
 */

/**
 * Argument handler to accept a node id.
 */
class koken_handler_argument_cid extends views_handler_argument_numeric {

  /**
   * The class contructor.
   */
  public function construct() {
    parent::construct();
    $this->additional_fields['data'] = 'data';
  }

  /**
   * Set up the query for this argument.
   *
   * The argument sent may be found at $this->argument.
   */
  function query($group_by = FALSE) {
    $this->ensure_my_table();
    $a = $this->view->args;
    $this->query->options['path'] = '/content/' . $this->argument;
  }
}
