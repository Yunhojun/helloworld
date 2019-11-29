using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Manager : MonoBehaviour
{
    GameObject mainc;
    GameObject subc;
<<<<<<< HEAD
    // Start is called before the first frame update
    void Start()
    {
=======
    GameObject ceil;
    // Start is called before the first frame update
    void Start()
    {
        ceil = GameObject.FindWithTag("Ceil");
>>>>>>> bf2650220ea0323615cdd027fb28ec567c9ec748
        mainc = GameObject.FindGameObjectWithTag("MainCamera");
        subc = GameObject.FindGameObjectWithTag("SubCamera");
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKeyDown(KeyCode.F))
        {
            CameraSwitch();
        }
    }

    void CameraSwitch()
    {
        if(mainc.GetComponent<Camera>().enabled == true)
        {
            mainc.GetComponent<Camera>().enabled = false;
            mainc.GetComponent<AudioListener>().enabled = false;
            subc.GetComponent<Camera>().enabled = true;
            subc.GetComponent<AudioListener>().enabled = true;
<<<<<<< HEAD
=======
            ceil.GetComponent<MeshRenderer>().enabled = false;  
>>>>>>> bf2650220ea0323615cdd027fb28ec567c9ec748
        }
        else
        {
            mainc.GetComponent<Camera>().enabled = true;
            mainc.GetComponent<AudioListener>().enabled = true;
            subc.GetComponent<Camera>().enabled = false;
            subc.GetComponent<AudioListener>().enabled = false;
<<<<<<< HEAD
        }
    }
=======
            ceil.GetComponent<MeshRenderer>().enabled = true;
        }        
    }   
>>>>>>> bf2650220ea0323615cdd027fb28ec567c9ec748
}
