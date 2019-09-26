using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerBehaviour : MonoBehaviour
{
    public GameObject obj = null;

    // Start is called before the first frame update
    void Start()
    {
        Transform PlayerTransform = GetComponent<Transform>();
    }

    // Update is called once per frame
    void Update()
    {
        if(Input.GetKey(KeyCode.Space)==true)
        {
            if(obj.transform.position.x >= 9.5f && obj.transform.position.x <= -8.5)
            {
                Destroy(obj,0f);            }
        }

    }
}
