<?php

/**
 * @file
 * Defines a basic field handler to display information about the album.
 */

/**
 * Field handler to display a basic text field.
 */
class koken_handler_album_cover_field extends views_handler_field_custom {

  /**
   * Keep field_alias synched with field name.
   */
  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
    $this->field_alias = $this->real_field;
  }

  /**
   * The class constructor.
   */
  public function construct() {
    parent::construct();
    $this->additional_fields['data'] = 'data';
  }

  function option_definition() {
    $options = parent::option_definition();
    $options['koken_cover_size'] = array('default' => 'tiny');
    $options['koken_cover_all'] = array('default' => FALSE);
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
    $form['koken_cover_all'] = array(
      '#type' => 'checkbox',
      '#title' => t('Render all covers ?'),
      '#description' => t('Koken handle 3 differents covers for each set. Check this if you want to display all those 3 covers.'),
      '#options' => array(
        '0' => t('Only the first one'),
        '1' => t('All'),
      ),
      '#default_value' => $this->options['koken_cover_all'],
      '#multiple' => FALSE,
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
    if ($this->options['koken_cover_all']) {
      $output = FALSE;
      foreach ($values->covers as $cover) {
        $output .= theme('image', array('path' => $cover->presets->{$this->options['koken_cover_size']}->url));
      }
      return $output;
    }
    else {
      return theme('image', array('path' => $values->covers[0]->presets->{$this->options['koken_cover_size']}->url));
    }

  }
}
