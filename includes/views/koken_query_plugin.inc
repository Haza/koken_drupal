<?php

/**
 * Custom query class to read information from the $COOKIE array.
 *
 * Our custom Query handler must be aware of some information about the current view.
 */
class koken_query_plugin extends views_plugin_query {

  /**
   * Create the basic query object and fill with default values.
   */
  public function init($base_table, $base_field, $options) {
    try {
      parent::init($base_table, $base_field, $options);
      $this->fields = array();
      $this->koken = koken_initialize_library();

    }
    catch (Exception $e) {
      $this->errors[] = $e->getMessage();
    }
  }
  function execute(&$view) {
    $args = $view->args;
    $koken = koken_initialize_library();
    $data = $koken->call($this->options['path']);
    if ($data) {
      $view->result = $data->albums;
    }
  }
  /**
   * Add settings for the ui.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
      $form['path'] = array(
        '#type' => 'textfield',
        '#description' => t('This is the patch you want to query.'),
        '#default_value' => $this->options['path'],
        '#required' => TRUE,
      );
  }

  function add_field($table, $field, $alias = '', $params = array()) {
    // Needed to avoid an ajax error when using the field.
  }

  function add_where() {
    return TRUE;
  }

  function add_orderby() {
    return TRUE;
  }
}

class koken_query_plugin_albums extends koken_query_plugin {
  /**
   * Execute the query.
   */
  function execute(&$view) {
    $args = $view->args;
    $koken = koken_initialize_library();
    $data = $koken->call($this->options['path']);
    if ($data) {
      $view->result = $data->albums;
    }
  }
}

class koken_query_plugin_content extends koken_query_plugin {
  /**
   * Execute the query.
   */
  function execute(&$view) {
    $args = $view->args;
    $koken = koken_initialize_library();
    $data = $koken->call($this->options['path']);
    if ($data) {
      $view->result = $data->content;
    }
  }
}
