let header = document.getElementById('header');
let degree = 0;

function rotateHeader() {
    degree += 6;
    degree %= 360;
    if (degree === 90) {
        header.setAttribute('class', 'back');
    } else if (degree === 270) {
        header.setAttribute('class', 'face');
    }
    header.style.transform = 'rotateX(' + degree + 'deg)';
}
setInterval(rotateHeader, 20);