$(document).ready(function() {
  if ($('#edit-recurring').attr('checked'))
    {
      $('#ms_recurring').show();
      $('#ms_expiration').hide();
    }
    else
    {
      $('#ms_recurring').hide();
      $('#ms_expiration').show();
    }
  $('#edit-recurring-wrapper').click(function(){
    if ($('#edit-recurring').attr('checked'))
    {
      $('#ms_recurring').show();
      $('#ms_expiration').hide();
    }
    else
    {
      $('#ms_recurring').hide();
      $('#ms_expiration').show();
    }
  });
});