using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Manager : MonoBehaviour
{
    GameObject mainc;
    GameObject subc;
    // Start is called before the first frame update
    void Start()
    {
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
        }
        else
        {
            mainc.GetComponent<Camera>().enabled = true;
            mainc.GetComponent<AudioListener>().enabled = true;
            subc.GetComponent<Camera>().enabled = false;
            subc.GetComponent<AudioListener>().enabled = false;
        }
    }
}
