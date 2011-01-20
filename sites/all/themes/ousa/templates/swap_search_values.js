$(function() {

    /*
        1.) Form Field Value Swap
    */

    swapValues = [];
    $(".swap_value").each(function(i){
        swapValues[i] = $(this).val();
        $(this).focus(function(){
            if ($(this).val() == swapValues[i]) {
                $(this).val("");
            }
        }).blur(function(){
            if ($.trim($(this).val()) == "") {
                $(this).val(swapValues[i]);
            }
        });
    });

});