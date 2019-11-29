using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CreateBoard : MonoBehaviour
{
    [SerializeField]
    GameObject Plane = null;
    GameObject Controller;
    bool color;
    int eff;
    GameObject Player;
    // Start is called before the first frame update
    void Start()
    {
        Player = GameObject.FindGameObjectWithTag("Player");
        Controller = GameObject.FindGameObjectWithTag("GameController");
        Create();
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKey(KeyCode.Escape))
        {
            deletEffect();
        }
    }

    void Create()
    {
        for (int x = -8; x < 8; x++)
        {
            for (int y = -8; y < 8; y++, color = !color)
            {
                GameObject NewObj = Instantiate<GameObject>(Plane, new Vector3(x * 2 +1, 0.1f, y * 2+1), Quaternion.identity);
                NewObj.GetComponent<Transform>().parent = Controller.transform;
                if (color)
                {
                    NewObj.GetComponent<MeshRenderer>().material.color = Color.black;
                }
                else
                {
                    NewObj.GetComponent<MeshRenderer>().material.color = Color.white;
                }
            }
            color = !color;
        }
    }

    void deletEffect()
    {
        GameObject effect = GameObject.FindGameObjectWithTag("effect");
        for (int i = 0; i < 100; i++)
        {
            Destroy(effect, 0f);
        }
    }
}
