let autoUnblock = setInterval(function() {
    window.scrollBy(0, window.innerHeight);
    document.querySelectorAll('[aria-label^="Blocked"]').forEach(function(account) {
        account.click()
    });
}, 1000);
