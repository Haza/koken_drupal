<?php

/**
 * Custom query class to read information from the $COOKIE array.
 *
 * Our custom Query handler must be aware of some information about the current view.
 */
class koken_query_plugin extends views_plugin_query {

  /**
   * Add settings for the ui.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['koken_url'] = array(
      '#type' => 'textfield',
      '#description' => t('The koken url.'),
      '#default_value' => !empty($this->options['koken_url']) ? $this->options['koken_url'] : FALSE,
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

abstract class koken_query_plugin_albums extends koken_query_plugin {
  /**
   * Execute the query.
   */
  function execute(&$view) {
    $args = $view->args;
    if (empty($this->options['koken_url'])) {
      drupal_set_message('The koken need to be set in the "query settings".', 'error');
    }
    else {
      $koken = koken_initialize_library($this->options['koken_url']);
      $data = $koken->call('/albums');
      if ($data) {
        $view->result = $data->albums;
      }
    }
  }
}

class koken_query_plugin_content extends koken_query_plugin {
  /**
   * Execute the query.
   */
  function execute(&$view) {
    $args = $view->args;
    if (empty($this->options['koken_url'])) {
      drupal_set_message('The koken need to be set in the "query settings".', 'error');
    }
    else {
      $koken = koken_initialize_library($this->options['koken_url']);
      // 'koken_query_path' came from the content argument handler.
      $data = $koken->call($this->options['koken_query_path']);
      if ($data) {
        if (!empty($data->filename)) {
          $view->result[] = $data;
        }
        else {
          $view->result = $data->content;
        }
      }
    }
  }
}
