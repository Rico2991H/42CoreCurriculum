rules for deconstructing a URL

is_page_candidate(url, allowed_domain):
    parse the url

    scheme not http or https?            → reject   (mailto:, tel:, javascript:)
    netloc empty?                        → reject   (broken / not absolute)
    netloc not the allowed domain?       → reject   (instagram, google maps)
    path ends with an image extension?   → reject   (already handled as image)
    path ends with a known non-page type → reject   (.pdf, .zip, .css, .js ... optional)

    → accept


    For spider: 
    For spider: this is the reason for the Content-Type check on image downloads. The server probably said Content-Type: image/webp. You could use that header to choose the extension, or skip formats outside the subject’s list. Either way, the file’s name would match its contents.