<?php
// $Id: $
/**
 * @file
 */

class ms_core_order_status_handler extends views_handler_field {
  function render($values) {
    return ms_core_get_order_status($values->{$this->field_alias});
  }
}