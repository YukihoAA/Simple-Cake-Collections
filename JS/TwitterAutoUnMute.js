let autoUnMute = setInterval(function() {
    window.scrollBy(0, window.innerHeight);
    document.querySelectorAll('[aria-label^="Unmute"]').forEach(function(account) {
        account.click()
    });
}, 1000);
