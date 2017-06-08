$(document).ready(function() {

  var isOver = false;
  var isClick = false;

  $("#btn1").mouseover(function() {
      isOver = true;
    }).mouseout(function() {
      isOver = false;
      if (isClick) {
        isClick = false;
        $(this).css({
          background: "red"
        });
      }
    }).mousedown(function() {
      if (isOver) {
        isClick = true;
        $(this).css({
          background: "blue"
        });
      }
    }).mouseup(function() {
      if (isOver && isClick) {
        isClick = false;
        $(this).css({
          background: "red"
        });
      }
    });
});

