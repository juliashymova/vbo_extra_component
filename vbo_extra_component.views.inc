<?php

function vbo_extra_component_views_data_alter(&$data) {
  foreach (entity_get_info() as $entity_type => $info) {
    if (isset($info['base table']) && isset($data[$info['base table']]['table'])) {
      $data[$info['base table']]['views_bulk_operations_extra'] = array(
          'title' => $data[$info['base table']]['table']['group'],
          'group' => t('Bulk operations extra'),
          'help' => t('Provide a checkbox to select the row for bulk operations (extra operation at the end).'),
          'real field' => $info['entity keys']['id'],
          'field' => array(
              'handler' => 'views_bulk_operations_extra_handler_field_operations',
              'click sortable' => FALSE,
          ),
      );
    }
  }

}