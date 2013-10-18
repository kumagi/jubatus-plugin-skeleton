#!/bin/sh

##################################
# example usage of jubaconv
##################################

# Standard input of jubaconv must be a JSON-formatted datum.

cat << '_EOF_' | jubaconv -i datum -o fv -c binary_server_config.json
{
  "num_values": {
  },
  "string_values": {
  },
"binary_values" : {
   "data3": "HOGEGEGEHOHGEOHOGHOEHOGHEOGE"
}

}
_EOF_
