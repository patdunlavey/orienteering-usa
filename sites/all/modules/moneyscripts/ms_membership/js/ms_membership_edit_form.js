$(document).ready(function() {
  if ($('#edit-should-expire').attr('checked'))
    {
      $('#edit-expiration-wrapper').show();
    }
    else
    {
      $('#edit-expiration-wrapper').hide();
    }
  $('#edit-should-expire-wrapper').click(function(){
    if ($('#edit-should-expire').attr('checked'))
    {
      $('#edit-expiration-wrapper').slideDown();
    }
    else
    {
      $('#edit-expiration-wrapper').slideUp();
    }
  });
});