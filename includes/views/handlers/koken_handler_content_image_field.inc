<?php

/**
 * @file
 * Defines a basic field handler to display information about the album.
 */

/**
 * Field handler to display a basic text field.
 */
class koken_handler_content_image_field extends views_handler_field_custom {

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

  function option_definition() {
    $options = parent::option_definition();
    $options['koken_cover_size'] = array('default' => 'tiny');
    return $options;

  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['koken_cover_size'] = array(
      '#type' => 'select',
      '#title' => t('Koken cover size'),
      '#description' => t('Select the size to be displayed.'),
      '#options' => array(
        'tiny' => t('Tiny'),
        'small' => t('Small'),
        'medium' => t('Medium'),
        'medium_large' => t('Medium large'),
        'large' => t('Large'),
        'xlarge' => t('Extra Large'),
        'huge' => t('Huge'),
      ),
      '#default_value' => $this->options['koken_cover_size'],
      '#multiple' => FALSE,
      '#required' => TRUE,
    );
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
    return theme('image', array('path' => $values->presets->{$this->options['koken_cover_size']}->url));
  }
}
