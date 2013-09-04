<?php

/**
 * @file
 * Views field handler. Contains all relevant VBO options and related logic.
 * Implements the Views Form API.
 */

class views_bulk_operations_extra_handler_field_operations extends views_bulk_operations_handler_field_operations {
  function option_definition() {
    $options = parent::option_definition();

    $options['vbo_extra_component'] = array('default' => NULL);

    return $options;
  }


  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $components = rules_get_components();
    $options = array();

    foreach ($components as $name => $component) {
      $options[$name] = $component->label;
    }

    $form['vbo_extra_component'] = array(
        '#type' => 'fieldset',
        '#title' => t('Extra operation'),
        '#collapsible' => TRUE,
    );

    $form['vbo_extra_component']['component'] = array(
        '#type' => 'select',
        '#title' => t('Extra operation'),
        '#description' => t('This operation will be executed after the VBO module has finished.'),
        '#options' => $options,
        '#empty_option' => t('-Select-'),
    );
  }
}
