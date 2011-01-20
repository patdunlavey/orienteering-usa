<?php
// $Id: $
/**
 * @file
 */

class ms_membership_status_handler extends views_handler_field {
  function render($values) {
    return ms_membership_get_membership_status_text($values->{$this->field_alias});
  }
}